import React from "react";
import NavigationItem from "./Item/item";
import styles from "./items.module.scss";
const items = () => {
  return (
    <ul className={styles.NavigationItems}>
      <NavigationItem link="/" active>
        Burger Builder
      </NavigationItem>
      <NavigationItem link="/">Checkout</NavigationItem>
    </ul>
  );
};

export default items;
