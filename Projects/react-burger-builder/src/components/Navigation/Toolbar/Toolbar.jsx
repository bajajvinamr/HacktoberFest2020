import React from "react";
import styles from "./Toolbar.module.scss";
import Logo from "../../Logo/Logo";
import NavigationItems from "../Items/items";
import DrawerToogle from "../SideDrawer/DrawerToogle/DrawerToogle";

const Toolbar = (props) => {
  return (
    <header className={styles.Toolbar}>
      <DrawerToogle clicked={props.clicked}>Menu</DrawerToogle>
      <div className={styles.Logo}>
        <Logo />
      </div>
      <nav className={styles.DesktopOnly}>
        <NavigationItems />
      </nav>
    </header>
  );
};

export default Toolbar;
