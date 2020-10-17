import { css } from "@emotion/core";

export const button = (props) => {
  let textColor;
  const {
    color: { primary },
  } = props.theme;

  switch (props.color) {
    case "black":
      textColor = primary.black;
      break;
    case "red":
      textColor = primary.red;
      break;
    default:
      textColor = primary.black;
      break;
  }

  return css`
    color: ${textColor};
    font-size: 2rem;
    background: unset;
    border: unset;
    outline: unset;
    padding: 16px;
    font-family: "Bungee", cursive;
    cursor: pointer;
  `;
};
