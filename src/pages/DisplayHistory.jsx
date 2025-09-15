import { useContext } from "react";
import { Trash2 } from "lucide-react";
import { HistoryContext } from "../context/HistoryContext";

function DisplayHistory() {
  const { history, setHistory } = useContext(HistoryContext);

  const handleDelete = (index) => {
    const updated = history.filter((_, i) => i !== index);
    setHistory(updated);
  };

  const handleClearAll = () => {
    if (window.confirm("Are you sure you want to clear all prediction history?")) {
      setHistory([]);
    }
  };

  return (
    <section className="max-w-6xl mx-auto px-6 py-12">
      <h2 className="text-3xl font-bold text-blue-600 mb-6 text-center">Prediction History</h2>

      {history.length === 0 ? (
        <p className="text-gray-600 text-center mt-6">No predictions found yet.</p>
      ) : (
        <>
          <div className="flex justify-end mb-4">
            <button
              onClick={handleClearAll}
              className="flex items-center gap-2 bg-red-600 hover:bg-red-700 text-white px-4 py-2 rounded-lg shadow transition"
            >
              <Trash2 className="w-4 h-4" /> Clear All
            </button>
          </div>

          <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 gap-6">
            {history.map((item, idx) => (
              <div key={idx} className="bg-white p-4 rounded-xl shadow hover:shadow-lg transition">
                <img
                  src={item.image}
                  alt={`History ${idx}`}
                  className="w-full h-40 object-cover rounded-lg mb-2"
                />
                <p className="text-gray-700 font-medium">
                  Prediction: <span className="text-blue-600">{item.result.predicted_class}</span>
                </p>
                <p className="text-gray-600 text-sm">
                  Confidence: {(item.result.confidence * 100).toFixed(2)}%
                </p>
                <p className="text-gray-500 text-xs mt-1">{new Date(item.timestamp).toLocaleString()}</p>
                <button
                  onClick={() => handleDelete(idx)}
                  className="flex items-center gap-1 mt-2 text-red-600 hover:text-red-700 text-sm"
                >
                  <Trash2 className="w-4 h-4" /> Delete
                </button>
              </div>
            ))}
          </div>
        </>
      )}
    </section>
  );
}

export default DisplayHistory;
