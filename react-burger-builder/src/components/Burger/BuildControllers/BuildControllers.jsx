import React from "react";
import styles from "./BuildControllers.module.scss";
import BuildController from "./BuildController/BuildController";

const controls = [
  { label: "Salad", type: "salad" },
  { label: "Bacon", type: "bacon" },
  { label: "Cheese", type: "cheese" },
  { label: "Meat", type: "meat" },
];

const BuildControllers = (props) => {
  return (
    <div className={styles.BuildControls}>
      <p>
        Current Price: <strong>{props.price.toFixed(2)}</strong>
      </p>
      {controls.map((ctrl) => {
        return (
          <BuildController
            added={() => props.ingredientAdded(ctrl.type)}
            key={ctrl.label}
            label={ctrl.label}
            remove={() => props.ingredientRemove(ctrl.type)}
            disabled={props.disabled[ctrl.type]}
          />
        );
      })}
      <button
        onClick={props.ordered}
        className={styles.OrderButton}
        disabled={!props.purchasable}
      >
        Order Now
      </button>
    </div>
  );
};
export default BuildControllers;
