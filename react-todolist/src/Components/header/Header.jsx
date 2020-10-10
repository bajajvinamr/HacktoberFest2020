import React from "react";
import PropTypes from "prop-types";
import Button from "../button/Button";
// import styles from "./Header.module.css";
import * as styles from "./header.styles";
import { useTheme } from "emotion-theming";
import Container from "../../Layout/Container";
import Item from "../../Layout/Item";

const Header = (props) => {
  const theme = useTheme();
  return (
    <section className="header-component">
      <Container alignItems={"flex-start"}>
        <Item flex={1}>
          <Button
            onClick={props.showAddToogle}
            text={props.showAdd ? "FINISHED" : "ADD"}
          />
        </Item>
        <Item flex={3}>
          <h1 css={styles.headerTitle({ theme })}>Todo List</h1>
        </Item>
        <Item flex={1} align={"right"}>
          <Button onClick={props.clearTodo} text="Clear" color="red" />
        </Item>
      </Container>
    </section>
  );
};

Header.propTypes = {
  showAddToogle: PropTypes.func.isRequired,
  showAdd: PropTypes.bool.isRequired,
  clearTodo: PropTypes.func.isRequired,
};
export default Header;
