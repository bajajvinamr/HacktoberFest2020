import React from "react";
import styles from "./DrawerToogle.module.scss";

const DrawerToogle = (props) => {
  return (
    <div className={styles.DrawerToggle} onClick={props.clicked}>
      <div></div>
      <div></div>
      <div></div>
    </div>
  );
};

export default DrawerToogle;
