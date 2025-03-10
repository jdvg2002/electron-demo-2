import React from "react";
import NavigationMenu from "@/components/ui/NavigationMenu";

export default function BaseLayout({ children }: { children: React.ReactNode }) {
    return (
        <>
            <NavigationMenu />
            <hr />
            <main>{children}</main>
        </>
    );
}
