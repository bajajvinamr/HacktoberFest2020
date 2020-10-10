import React from "react";
import PropTypes from "prop-types";
import * as styles from "./button.styles";
// import styles from "./button.module.css";
import { useTheme } from "emotion-theming";

const Button = ({ color, onClick, text }) => {
  // const className = [
  //   styles.headerBtn,
  //   props.color === "black" && styles.mainBlackColor,
  //   props.color === "red" && styles.mainRedColor,
  // ].join(" ");

  const theme = useTheme();

  return (
    <button css={styles.button({ color, theme })} onClick={onClick}>
      {text}
    </button>
  );
};

Button.defaultProps = {
  text: "Button",
  color: "black",
};

Button.propTypes = {
  onClick: PropTypes.func.isRequired,
  text: PropTypes.string.isRequired,
  color: PropTypes.oneOf(["black", "red"]),
};

export default Button;
