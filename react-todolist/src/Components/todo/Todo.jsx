import React from "react";
import PropTypes from "prop-types";
// import styles from "./Todo.module.css";
import * as styles from "./Todo.styles";
import { useTheme } from "emotion-theming";

const Todo = ({ completeTodo, index, isComplete, text }) => {
  const theme = useTheme();
  return (
    <div css={styles.todo({ theme })} onClick={() => completeTodo(index)}>
      <span css={styles.todoText({ theme, isComplete })}>{text}</span>
    </div>
  );
};

Todo.propTypes = {
  text: PropTypes.string.isRequired,
  completeTodo: PropTypes.func.isRequired,
  index: PropTypes.number.isRequired,
  isComplete: PropTypes.bool.isRequired,
};

export default Todo;
