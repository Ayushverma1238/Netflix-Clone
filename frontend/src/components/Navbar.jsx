import { Microscope, Menu, X } from "lucide-react";
import { useState } from "react";
import { Link } from "react-router-dom";

function Navbar() {
  const [isActive, setIsActive] = useState("/");
  const [isOpen, setIsOpen] = useState(false);

  const navLinks = [
    { name: "Home", path: "/" },
    { name: "About", path: "/about" },
    { name: "Team", path: "/team" },
    { name: "Contact", path: "/contact" },
    { name: "History", path: "/displayhistory" },
  ];

  return (
    <header className="w-full bg-white border-b shadow-sm">
      <nav className="max-w-6xl mx-auto flex justify-between items-center py-3 px-6">
        {/* Logo */}
        <Link
          to="/"
          onClick={() => {
            setIsActive("/");
            setIsOpen(false);
          }}
          className="flex items-center gap-2 text-xl font-semibold text-gray-800"
        >
          <Microscope className="w-6 h-6 text-blue-600" />
          CellScope AI
        </Link>

        {/* Desktop Links */}
        <ul className="hidden md:flex gap-6 text-gray-700 text-sm font-medium">
          {navLinks.map((link) => (
            <li key={link.path}>
              <Link
                to={link.path}
                onClick={() => setIsActive(link.path)}
                className={`hover:text-blue-600 ${
                  isActive === link.path
                    ? "text-blue-600 border-b-2 border-blue-600 pb-1"
                    : "text-gray-700"
                }`}
              >
                {link.name}
              </Link>
            </li>
          ))}
        </ul>

        {/* Mobile Hamburger */}
        <button
          className="md:hidden p-2 text-gray-700"
          onClick={() => setIsOpen(!isOpen)}
        >
          {isOpen ? <X className="w-6 h-6" /> : <Menu className="w-6 h-6" />}
        </button>
      </nav>

      {/* Mobile Menu */}
      {isOpen && (
        <div className="md:hidden bg-white border-t shadow-sm">
          <ul className="flex flex-col gap-4 px-6 py-4 text-gray-700 text-sm font-medium">
            {navLinks.map((link) => (
              <li key={link.path}>
                <Link
                  to={link.path}
                  onClick={() => {
                    setIsActive(link.path);
                    setIsOpen(false);
                  }}
                  className={`block w-full hover:text-blue-600 ${
                    isActive === link.path ? "text-blue-600 font-semibold" : ""
                  }`}
                >
                  {link.name}
                </Link>
              </li>
            ))}
          </ul>
        </div>
      )}
    </header>
  );
}

export default Navbar;
