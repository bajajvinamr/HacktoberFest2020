import React, { Fragment, useState } from "react";
import styles from "./Layout.module.scss";
import Toolbar from "../Navigation/Toolbar/Toolbar";
import SideDrawer from "../Navigation/SideDrawer/SideDrawer";

const Layout = (props) => {
  const [showSideDrawer, setShowSideDrawer] = useState(false);

  const SideDrawerHandler = () => {
    setShowSideDrawer(!showSideDrawer);
  };

  return (
    <Fragment>
      <Toolbar clicked={SideDrawerHandler} />
      <SideDrawer open={showSideDrawer} close={SideDrawerHandler} />
      <div className={styles.Content}> {props.children} </div>
    </Fragment>
  );
};

export default Layout;
