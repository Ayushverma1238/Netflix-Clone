import { Heart } from "lucide-react";

function Footer() {
  return (
    <footer className="bg-gray-100 border-t mt-10">
      <div className="max-w-6xl mx-auto px-6 py-6 flex flex-col md:flex-row justify-between items-center text-gray-700 text-sm">
        <div className="flex items-center gap-1 mb-3 md:mb-0">
          © {new Date().getFullYear()} <span className="font-semibold">CellScope AI</span> | Built with
          <Heart className="w-4 h-4 text-red-500 inline-block mx-1" /> React & TensorFlow
        </div>

        <div className="flex flex-col md:flex-row items-center gap-2 md:gap-6 text-gray-600">
          <span>Minor Project - Babu Banarasi Das University</span>
          <span>Developed by Team CellScope</span>
        </div>
      </div>
    </footer>
  );
}

export default Footer;
