import React from "react";
import { Users, Mail, Phone } from "lucide-react";

function Contact() {
  return (
    <section className="max-w-5xl mx-auto px-6 py-16">
      {/* Header */}
      <div className="text-center mb-12">
        <h2 className="flex items-center justify-center gap-3 text-4xl font-extrabold text-blue-700 mb-4">
          <Users className="w-8 h-8 text-indigo-600" />
          Contact & Team
        </h2>
        <p className="text-gray-600 max-w-2xl mx-auto">
          Get in touch with the project team or our guide for queries, suggestions, 
          or feedback about <span className="font-semibold">CellScope AI</span>.
        </p>
      </div>

      {/* Team Info */}
      <div className="grid grid-cols-1 sm:grid-cols-2 gap-8 mb-12">
        <div className="bg-white p-6 rounded-2xl shadow-md text-center">
          <h3 className="text-xl font-semibold text-gray-800 mb-2">Project Team</h3>
          <p className="text-gray-700 mb-1">Avanish Dubey – ML Engineer</p>
          <p className="text-gray-700 mb-1">Anurag Yadav – Frontend Developer</p>
          <p className="text-gray-700 mb-1">Ayush Verma – Backend Developer</p>
          <p className="text-gray-700 mb-1">Balwant Singh – Documentation & Testing</p>
        </div>

        <div className="bg-white p-6 rounded-2xl shadow-md text-center">
          <h3 className="text-xl font-semibold text-gray-800 mb-2">Project Guide</h3>
          <p className="text-gray-700 mb-1">Dr. Adarsh Kumar Srivastava</p>
          <p className="text-gray-700 mb-1">Associate Professor, Computer Science</p>
        </div>
      </div>

      {/* Contact Info */}
      <div className="bg-blue-50 p-8 rounded-2xl shadow-inner text-center">
        <h3 className="text-2xl font-semibold text-gray-800 mb-4">Contact</h3>
        <p className="flex items-center justify-center gap-2 text-gray-700 mb-2">
          <Mail className="w-5 h-5 text-blue-600" /> 
          <span>cellscope.ai@example.com</span>
        </p>
        <p className="flex items-center justify-center gap-2 text-gray-700">
          <Phone className="w-5 h-5 text-blue-600" /> 
          <span>+91-XXXXXXXXXX</span>
        </p>
        <p className="text-gray-600 mt-4 text-sm">
          For any project-related queries, collaboration, or feedback, feel free to contact the team.
        </p>
      </div>
    </section>
  );
}

export default Contact;
