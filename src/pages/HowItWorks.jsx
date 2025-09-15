import React from "react";
import { Workflow, Upload, ScanLine, CheckCircle2 } from "lucide-react";

function HowItWorks() {
  return (
    <section className="max-w-4xl mx-auto px-6 py-12">
      <h2 className="flex items-center gap-2 text-3xl font-bold text-blue-600 mb-8">
        <Workflow className="w-7 h-7 text-indigo-600" />
        How It Works
      </h2>
      <ol className="space-y-6">
        <li className="flex items-center gap-3">
          <Upload className="w-6 h-6 text-blue-600" />
          <span>Upload microscopy image of the cell.</span>
        </li>
        <li className="flex items-center gap-3">
          <ScanLine className="w-6 h-6 text-indigo-600" />
          <span>Image is processed using a Convolutional Neural Network (CNN).</span>
        </li>
        <li className="flex items-center gap-3">
          <CheckCircle2 className="w-6 h-6 text-green-600" />
          <span>AI model predicts if the cell is <b>cancerous</b> or <b>non-cancerous</b>.</span>
        </li>
      </ol>
    </section>
  );
}

export default HowItWorks;
