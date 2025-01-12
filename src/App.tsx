import React, { useEffect } from "react";
import { createRoot } from "react-dom/client";
import { syncThemeWithLocal } from "./helpers/theme_helpers";
import { useTranslation } from "react-i18next";
import "./localization/i18n";
import { updateAppLanguage } from "./helpers/language_helpers";
import { router } from "./routes/router";
import { RouterProvider } from "@tanstack/react-router";
import Demo from "./components/nuclear/demo";

export default function App() {
}

// Single render point
const root = createRoot(document.getElementById("app")!);
root.render(
    <Demo />
);