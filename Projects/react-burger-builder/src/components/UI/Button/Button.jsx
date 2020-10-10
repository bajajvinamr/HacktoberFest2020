import React from "react";
import styles from "./Button.module.scss";

const Button = (props) => {
  return (
    <button
      onClick={props.clicked}
      className={[styles.Button, styles[props.btnType]].join(" ")}
    >
      {props.children}
    </button>
  );
};

export default Button;
