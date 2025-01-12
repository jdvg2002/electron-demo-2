import { createRoute } from "@tanstack/react-router";
import { RootRoute } from "./__root";
import Demo from "@/components/nuclear/demo";
import Dashboard from "@/components/nuclear/dashboard";

export const HomeRoute = createRoute({
    getParentRoute: () => RootRoute,
    path: "/",
    component: Dashboard,
});

export const DemoRoute = createRoute({
    getParentRoute: () => RootRoute,
    path: "/demo/$cardId",
    component: Demo,
});

export const rootTree = RootRoute.addChildren([HomeRoute, DemoRoute]);
