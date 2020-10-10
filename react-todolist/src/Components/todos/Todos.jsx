import React from "react";
import Todo from "../todo/Todo";
import PropTypes from "prop-types";
// import styles from "./Todos.module.css";
import * as styles from "./Todos.styles";

const Todos = (props) => {
  return (
    <section css={styles.todos}>
      {props.todos.length > 0 &&
        props.todos.map((todo, index) => {
          return (
            <Todo
              key={index}
              text={todo.text}
              isComplete={todo.isComplete}
              completeTodo={props.completeTodo}
              index={index}
            />
          );
        })}
      {props.todos.length === 0 && (
        <div css={styles.todoPlaceholderText}>
          Add todo by clicking{" "}
          <span css={styles.addButtonPlaceholderText}>Add</span> button on the
          top left corner
        </div>
      )}
    </section>
  );
};

Todos.propTypes = {
  todos: PropTypes.arrayOf(
    PropTypes.shape({
      text: PropTypes.string,
      isComplete: PropTypes.bool,
    })
  ),
  completeTodo: PropTypes.func.isRequired,
};

export default Todos;
