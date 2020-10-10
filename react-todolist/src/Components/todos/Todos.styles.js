import { css } from "@emotion/core";

export const todos = () => {
  return css`
    display: flex;
    flex-direction: column;
    min-height: 500px;
  `;
};

export const todoPlaceholderText = () => {
  return css`
    font-family: "Gloria Hallelujah", cursive;
    font-size: 24px;
    text-align: center;
    padding: 16px;
  `;
};

export const addButtonPlaceholderText = () => {
  return css`
    font-family: "Bungee", cursive;
  `;
};
