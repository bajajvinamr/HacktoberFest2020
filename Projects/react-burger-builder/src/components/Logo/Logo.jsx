import React from "react";
import burgerLogo from "../../assets/Image/burger-logo.png";
import styles from "./Logo.module.scss";

const Logo = () => {
  return (
    <div className={styles.Logo}>
      <img src={burgerLogo} alt="Burger Logo" />
    </div>
  );
};

export default Logo;
