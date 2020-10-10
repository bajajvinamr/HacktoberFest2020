import React, { Fragment } from "react";
import styles from "./Modal.module.scss";
import Backdrop from "../Backdrop/Backdrop";

const Modal = (props) => {
  return (
    <Fragment>
      <Backdrop show={props.show} clicked={props.modalClosed}>
        <div
          style={{
            transform: props.show ? "translate(0)" : "translateY(-100vh)",
            opacity: props.show ? "1" : "0",
          }}
          className={styles.Modal}
        >
          {props.children}
        </div>
      </Backdrop>
    </Fragment>
  );
};

export default Modal;
