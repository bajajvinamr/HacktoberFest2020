import React from "react";
import styles from "./BuildController.module.scss";

const BuildController = (props) => {
  return (
    <div className={styles.BuildControl}>
      <div className={styles.Label}>{props.label}</div>
      <button
        className={styles.Less}
        onClick={props.remove}
        disabled={props.disabled}
      >
        Less
      </button>
      <button className={styles.More} onClick={props.added}>
        More
      </button>
    </div>
  );
};

export default BuildController;
