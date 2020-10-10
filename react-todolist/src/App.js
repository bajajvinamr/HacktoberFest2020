import React from "react";
import "./App.css";
import TodoList from "./Pages/TodoList";
import { ThemeProvider } from "emotion-theming";

const theme = {
  color: {
    primary: {
      black: "#26292d",
      red: "#f11c1f",
    },
  },
  background: {
    color: {
      primary: "#feb575",
    },
  },
};

function App() {
  return (
    <ThemeProvider theme={theme}>
      <TodoList />
    </ThemeProvider>
  );
}

export default App;
