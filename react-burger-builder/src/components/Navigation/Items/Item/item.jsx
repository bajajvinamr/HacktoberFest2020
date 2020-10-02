import React from "react";
import styles from "./item.module.scss";

const item = (props) => {
  return (
    <li className={styles.NavigationItem}>
      <a href={props.link} className={props.active ? styles.active : null}>
        {props.children}
      </a>
    </li>
  );
};

export default item;
