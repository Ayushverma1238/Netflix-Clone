import React from "react";
import { Info, Target, Rocket, Cpu } from "lucide-react";

function About() {
  return (
    <section className="max-w-6xl mx-auto px-6 py-12">
      {/* Heading */}
      <h2 className="flex items-center gap-2 text-3xl font-bold text-gray-800 mb-6">
        <Info className="w-7 h-7 text-blue-600" />
        About the Project
      </h2>

      {/* Intro */}
      <p className="text-gray-700 leading-relaxed mb-6 text-justify">
        <span className="font-semibold text-blue-600">CellScope AI</span> is a{" "}
        <span className="font-semibold">college minor project</span> developed
        to demonstrate the potential of{" "}
        <span className="font-semibold">Artificial Intelligence</span> in the
        field of medical diagnostics. The project uses{" "}
        <span className="font-semibold">Deep Learning (CNN)</span> techniques to
        classify microscopy images as <span className="italic">cancerous</span>{" "}
        or <span className="italic">non-cancerous</span>. The goal is to
        highlight how AI-driven approaches can support early detection,
        efficient diagnosis, and research in healthcare.
      </p>

      {/* Grid Info */}
      <div className="grid md:grid-cols-3 gap-6 mb-10">
        <div className="p-5 border rounded-lg shadow-sm bg-white hover:shadow-md transition">
          <h3 className="text-lg font-semibold text-blue-600 mb-2">
            Dataset
          </h3>
          <p className="text-gray-700 text-sm leading-relaxed">
            We used the{" "}
            <span className="font-semibold">[Dataset Name]</span> dataset with
            thousands of labeled cell images. It provided a diverse set of
            cancerous and non-cancerous samples for training and evaluation.
          </p>
        </div>

        <div className="p-5 border rounded-lg shadow-sm bg-white hover:shadow-md transition">
          <h3 className="text-lg font-semibold text-blue-600 mb-2">
            Model
          </h3>
          <p className="text-gray-700 text-sm leading-relaxed">
            Our approach is based on a{" "}
            <span className="font-semibold">Convolutional Neural Network (CNN)</span>{" "}
            trained using <span className="font-semibold">TensorFlow / Keras</span>.
            The model was fine-tuned with optimized hyperparameters for
            better accuracy.
          </p>
        </div>

        <div className="p-5 border rounded-lg shadow-sm bg-white hover:shadow-md transition">
          <h3 className="text-lg font-semibold text-blue-600 mb-2">
            Performance
          </h3>
          <p className="text-gray-700 text-sm leading-relaxed">
            The system achieved{" "}
            <span className="font-semibold">XX% accuracy</span> on test data,
            demonstrating its effectiveness in distinguishing between
            cancerous and healthy cells.
          </p>
        </div>
      </div>

      {/* Motivation */}
      <div className="mb-10">
        <h3 className="flex items-center gap-2 text-2xl font-semibold text-gray-800 mb-4">
          <Target className="w-6 h-6 text-blue-600" />
          Motivation
        </h3>
        <p className="text-gray-700 leading-relaxed text-justify">
          Cancer is one of the leading causes of death worldwide. Early
          detection plays a critical role in successful treatment, yet manual
          diagnosis through microscopy can be time-consuming and error-prone.
          Our project was motivated by the need for{" "}
          <span className="font-semibold">AI-based solutions</span> that can
          provide fast, accurate, and reliable results to assist medical
          professionals and researchers.
        </p>
      </div>

      {/* Objectives */}
      <div className="mb-10">
        <h3 className="flex items-center gap-2 text-2xl font-semibold text-gray-800 mb-4">
          <Rocket className="w-6 h-6 text-blue-600" />
          Objectives
        </h3>
        <ul className="list-disc pl-6 text-gray-700 leading-relaxed space-y-2">
          <li>
            To develop a deep learning model capable of detecting cancer cells
            from microscopy images.
          </li>
          <li>
            To provide an easy-to-use interface for uploading images and viewing
            predictions.
          </li>
          <li>
            To analyze the performance of CNNs in medical image classification.
          </li>
          <li>
            To demonstrate how AI can support healthcare applications as part of
            an academic project.
          </li>
        </ul>
      </div>

      {/* Tech Stack */}
      <div className="mb-10">
        <h3 className="flex items-center gap-2 text-2xl font-semibold text-gray-800 mb-4">
          <Cpu className="w-6 h-6 text-blue-600" />
          Technology Stack
        </h3>
        <ul className="list-disc pl-6 text-gray-700 leading-relaxed space-y-2">
          <li>Frontend: React, Tailwind CSS, Lucide Icons, React-Router-Dom</li>
          <li>Backend: Flask (Python)</li>
          <li>Machine Learning: TensorFlow, Keras, NumPy, Pandas</li>
          <li>Deployment: Localhost / Cloud (future scope)</li>
        </ul>
      </div>

      {/* Future Scope */}
      <div>
        <h3 className="flex items-center gap-2 text-2xl font-semibold text-gray-800 mb-4">
          <Rocket className="w-6 h-6 text-blue-600" />
          Future Scope
        </h3>
        <p className="text-gray-700 leading-relaxed text-justify">
          While this project is currently designed as a proof-of-concept, future
          improvements may include expanding the dataset, integrating cloud-based
          APIs for real-time diagnosis, adding multi-class cancer detection, and
          building a complete medical assistance tool for hospitals and research
          labs.
        </p>
      </div>
    </section>
  );
}

export default About;
