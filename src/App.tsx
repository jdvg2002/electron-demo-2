import React, { useEffect } from "react";
import { createRoot } from "react-dom/client";
import { syncThemeWithLocal } from "./helpers/theme_helpers";
import { useTranslation } from "react-i18next";
import "./localization/i18n";
import { updateAppLanguage } from "./helpers/language_helpers";
import { router } from "./routes/router";
import { RouterProvider } from "@tanstack/react-router";
import Demo from "./components/nuclear/demo";
import Titlebar from './components/Titlebar';
import Dashboard from "./components/nuclear/dashboard";

export default function App() {
  return (
    <>
      <Titlebar />
      <Demo />
    </>
  );
}

// Single render point
const root = createRoot(document.getElementById("app")!);
root.render(
  <App />
);