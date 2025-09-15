import { Users, GraduationCap, UserCheck } from "lucide-react";

function Team() {
  const members = [
    { name: "Avanish Dubey", role: "AI Engineer", skills: "Python, TensorFlow, Keras" },
    { name: "Anurag Yadav", role: "Fullstack Developer", skills: "React, Tailwind CSS, JavaScript, Java, Spring" },
    { name: "Ayush Verma", role: "Backend Developer", skills: "Flask, Python, MySQL" },
    { name: "Balwant Singh", role: "Frontend Developer ", skills: "HTML, CSS, JavaScript" },
  ];

  return (
    <section className="max-w-7xl mx-auto px-6 py-16">
      {/* Header */}
      <div className="text-center mb-12">
        <h2 className="flex items-center justify-center gap-3 text-4xl font-extrabold text-blue-700 mb-4">
          <Users className="w-8 h-8 text-indigo-600" />
          Meet Our Team
        </h2>
        <p className="text-gray-600 max-w-2xl mx-auto">
          The talented group behind <span className="font-semibold">CellScope AI</span>. Each member
          contributed their skills to make this minor project a success.
        </p>
      </div>

      {/* College Info */}
      <div className="bg-gradient-to-r from-blue-50 to-white p-8 rounded-2xl shadow-md mb-12 text-center">
        <h3 className="flex items-center justify-center gap-2 text-2xl font-semibold text-gray-800 mb-2">
          <GraduationCap className="w-6 h-6 text-blue-600" />
          Babu Banarasi Das University, Lucknow
        </h3>
        <p className="text-gray-600 text-sm md:text-base">
          Minor Project submitted in partial fulfillment of the requirements for
          the Bachelor of Technology (B.Tech). This project showcases collaboration,
          coding, and research under expert faculty guidance.
        </p>
      </div>

      {/* Team Members */}
      <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-8 mb-12">
        {members.map((member, idx) => (
          <div
            key={idx}
            className="bg-white border border-gray-200 p-6 rounded-2xl shadow hover:shadow-xl transition-all"
          >
            <h4 className="text-xl font-semibold text-gray-800 mb-1">{member.name}</h4>
            <p className="text-blue-600 font-medium mb-2">{member.role}</p>
            <p className="text-gray-600 text-sm">{member.skills}</p>
          </div>
        ))}
      </div>

      {/* Project Guide */}
      <div className="bg-white p-8 rounded-2xl shadow-md text-center mb-12">
        <h3 className="flex items-center justify-center gap-2 text-2xl font-semibold text-gray-800 mb-2">
          <UserCheck className="w-6 h-6 text-blue-600" />
          Project Guide
        </h3>
        <p className="text-gray-700 font-medium text-lg mb-1">Dr. Adarsh Kumar Srivastava</p>
        <p className="text-gray-600 mb-2">Associate Professor, Computer Science</p>
        <p className="text-gray-600 text-sm">
          Provided guidance and mentorship throughout the project, ensuring technical
          excellence and academic standards.
        </p>
      </div>

      {/* Footer Note */}
      <div className="bg-blue-50 p-6 rounded-xl shadow-inner text-center">
        <p className="text-gray-700 text-sm md:text-base">
          The team collectively worked on research, coding, testing, and documentation
          to make <span className="font-semibold">CellScope AI</span> a successful minor project.
        </p>
      </div>
    </section>
  );
}

export default Team;
