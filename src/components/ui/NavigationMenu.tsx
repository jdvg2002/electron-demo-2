import { Link } from "@tanstack/react-router";
import React from "react";

export default function NavigationMenu() {
    return (
        <nav>
            <ul className="flex bg-[#003449] gap-2 p-2 text-sm text-white">
                <li>
                    <Link to="/">Home</Link>
                </li>
                <li>
                    <Link to="/about">
                        About
                    </Link>
                </li>
            </ul>
        </nav>
    );
}
