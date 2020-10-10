import React, { useState, useRef, useEffect } from "react";
import PropTypes from "prop-types";
// import styles from "./TodoForm.module.css";
import * as styles from "./TodoForm.styles";
import { useTheme } from "emotion-theming";
import Container from "../../Layout/Container";
import Item from "../../Layout/Item";

const Todoform = (props) => {
  const theme = useTheme();
  // todo : Hook Input
  const [inputState, setInputState] = useState("");

  // todo: ref={inputFocus}
  const inputFocus = useRef(null);
  useEffect(() => {
    inputFocus.current.focus();
  });

  const handleFormSumbit = (event) => {
    event.preventDefault();
    if (!inputState) {
      alert("No Blank Todo!");
      return;
    }
    props.addTodo(inputState);
    setInputState("");
  };

  if (inputState.length > 40) {
    setInputState("");
    alert("Please create a shorter todo text!");
    return;
  }

  return (
    <section css={styles.add}>
      <Container alignItems={"flex-start"}>
        <form action="" onSubmit={handleFormSumbit}>
          <input
            ref={inputFocus}
            type="text"
            css={styles.addInput({ theme })}
            value={inputState}
            onChange={(event) => setInputState(event.target.value)}
          />
          <button css={styles.addBtn({ theme })}>Add</button>
        </form>
      </Container>
    </section>
  );
};

Todoform.propTypes = {
  addTodo: PropTypes.func.isRequired,
};

export default Todoform;
