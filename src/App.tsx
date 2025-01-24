import React from "react";
import { createRoot } from "react-dom/client";
import { RouterProvider } from "@tanstack/react-router";
import { router } from "./routes/router";
import Titlebar from './components/ui/Titlebar';

export default function App() {
  return (
    <>
      <Titlebar />
      <RouterProvider router={router} />
    </>
  );
}

const root = createRoot(document.getElementById("app")!);
root.render(<App />);
