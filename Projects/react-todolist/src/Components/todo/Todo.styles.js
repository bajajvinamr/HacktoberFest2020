import { css } from "@emotion/core";

export const todo = ({ theme }) => {
  return css`
    position: relative;
    flex: 1 0 auto;
    max-height: 34px;
    margin: 16px 0 0;
    font-family: "Gloria Hallelujah", cursive;
    font-size: 24px;
    border-bottom: 1px solid ${theme.color.primary.black};
    text-align: center;
  `;
};

export const todoText = ({ theme, isComplete }) => {
  return css`
    width: 100%;
    height: 50px;
    position: absolute;
    left: 50%;
    transform: translate(-50%);
    color: ${theme.color.primary.black};
    text-decoration: ${isComplete ? "line-through" : "initial"};
  `;
};
