import React, { useState, useContext } from "react";
import { Microscope, Upload, ScanLine, Loader2, CheckCircle2 } from "lucide-react";
import { HistoryContext } from "../context/HistoryContext";

function Home() {
  const [image, setImage] = useState(null);
  const [preview, setPreview] = useState(null);
  const [result, setResult] = useState(null);
  const [loading, setLoading] = useState(false);
  const { history, setHistory } = useContext(HistoryContext);

  const validTypes = ["image/png", "image/jpeg", "image/tiff", "image/bmp"];

  const handleFileChange = (e) => {
    const file = e.target.files[0];
    if (!file) return;

    if (!validTypes.includes(file.type)) {
      alert("Please upload a valid microscopy or X-ray image (PNG, JPG, TIFF, BMP).");
      e.target.value = null;
      return;
    }

    const img = new Image();
    img.src = URL.createObjectURL(file);
    img.onload = () => {
      if (img.width < 200 || img.height < 200) {
        alert("Image too small for proper analysis. Please upload a clearer microscopy/X-ray image.");
        setImage(null);
        setPreview(null);
        return;
      }
      setImage(file);
      setPreview(img.src);
      setResult(null);
    };
  };

  const handleSubmit = async () => {
    if (!image) {
      alert("Please upload an image first.");
      return;
    }

    const formData = new FormData();
    formData.append("image", image);

    setLoading(true);
    try {
      const response = await fetch("http://localhost:5000/predict", {
        method: "POST",
        body: formData,
      });
      const data = await response.json();

      const newRecord = {
        image: preview,
        result: data,
        timestamp: new Date().toISOString(),
      };

      setHistory((prev) => [newRecord, ...prev]); // prepend new prediction
      setResult(data);
    } catch (error) {
      console.error("Error:", error);
      alert("Something went wrong!");
    }
    setLoading(false);
  };

  return (
    <div className="min-h-screen flex flex-col bg-gradient-to-br from-blue-50 via-white to-blue-100 px-6">
      <section className="flex-1 flex flex-col items-center justify-center text-center py-16 max-w-3xl mx-auto w-full">
        <h2 className="text-4xl md:text-5xl font-extrabold bg-gradient-to-r from-blue-600 to-indigo-600 bg-clip-text text-transparent drop-shadow mb-4">
          Detect Cancer Cells with AI
        </h2>
        <p className="text-gray-700 max-w-2xl mb-10">
          Upload your microscopy or X-ray image and our deep learning model will classify it as{" "}
          <span className="font-semibold">cancerous</span> or <span className="font-semibold">non-cancerous</span>, along with confidence levels.
        </p>

        <div className="bg-white shadow-2xl rounded-3xl p-8 w-full max-w-lg transform transition hover:scale-[1.01]">
          <label className="block text-gray-700 font-medium mb-2">Upload Microscopy/X-ray Image</label>
          <div className="flex items-center gap-2 mb-4">
            <Upload className="w-5 h-5 text-blue-600" />
            <input
              type="file"
              accept=".png,.jpg,.jpeg,.tif,.tiff,.bmp"
              onChange={handleFileChange}
              className="block w-full text-sm text-gray-600 file:mr-4 file:py-2 file:px-4 
              file:rounded-lg file:border-0 file:text-sm file:font-semibold 
              file:bg-blue-600 file:text-white hover:file:bg-blue-700 cursor-pointer"
            />
          </div>

          {preview && (
            <div className="mb-4">
              <img
                src={preview}
                alt="Preview"
                className="rounded-2xl shadow-lg w-full h-64 object-cover border border-gray-200"
              />
            </div>
          )}

          <button
            onClick={handleSubmit}
            disabled={loading}
            className="w-full flex items-center justify-center gap-2 py-3 bg-gradient-to-r from-blue-600 to-indigo-600 text-white font-semibold rounded-xl shadow-lg hover:opacity-90 disabled:opacity-50 transition"
          >
            {loading ? (
              <>
                <Loader2 className="w-5 h-5 animate-spin" />
                Detecting...
              </>
            ) : (
              <div className="flex items-center">
                <ScanLine className="w-5 mr-2 h-5" />
                Detect Cancer Cells
              </div>
            )}
          </button>
        </div>

        {result && (
          <div className="mt-10 bg-white shadow-2xl rounded-3xl p-8 w-full max-w-lg text-center animate-fadeIn">
            <h2 className="flex items-center justify-center gap-2 text-2xl font-bold text-gray-800">
              <CheckCircle2 className="w-6 h-6 text-green-600" />
              Prediction: <span className="text-blue-600">{result.predicted_class}</span>
            </h2>
            <p className="text-gray-600 mt-1">
              Confidence: <span className="font-semibold">{(result.confidence * 100).toFixed(2)}%</span>
            </p>
          </div>
        )}
      </section>
    </div>
  );
}

export default Home;
