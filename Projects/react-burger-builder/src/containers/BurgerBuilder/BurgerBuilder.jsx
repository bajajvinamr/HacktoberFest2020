import React, { Fragment, useState } from "react";
import Burger from "../../components/Burger/Burger";
import BuildControllers from "../../components/Burger/BuildControllers/BuildControllers";
import Modal from "../../components/UI/Modal/Modal";
import OrderSummary from "../../components/Burger/OrderSummary/OrderSummary";

// todo: Adding price
const INGREDIENT_PRICES = {
  salad: 0.5,
  cheese: 0.4,
  meat: 1.3,
  bacon: 0.7,
};

const BurgerBuilder = (pros) => {
  // todo: Hooks Ingredients Burger
  const [ingredients, setIngredients] = useState({
    cheese: 0,
    salad: 0,
    meat: 0,
    bacon: 0,
  });

  // todo: Hooks Price Burger
  const [totalPrice, setTotalPrice] = useState(0);

  // todo: Hooks Purchasable
  const [purchasable, setPurchasable] = useState(false);

  // todo: Hooks Purchasing
  const [purchasing, setPurchasing] = useState(false);

  // todo: updatePurchase()
  const updatePurchase = (ingredients) => {
    const sum = Object.keys(ingredients)
      .map((igKey) => {
        return ingredients[igKey];
      })
      .reduce((sum, el) => {
        return sum + el;
      }, 0);
    setPurchasable(sum > 0);
  };

  // todo: ingredientAdded={addIngredientHandler}
  const addIngredientHandler = (type) => {
    const oldCount = ingredients[type];
    const updateCount = oldCount + 1;
    const updateIngredients = {
      ...ingredients,
    };
    updateIngredients[type] = updateCount;
    const priceAddition = INGREDIENT_PRICES[type];
    const oldPrice = totalPrice;
    const newPrice = oldPrice + priceAddition;
    setIngredients(updateIngredients);
    setTotalPrice(newPrice);
    updatePurchase(updateIngredients);
  };

  // todo: ingredientRemove={removingIngredientHandler}
  const removingIngredientHandler = (type) => {
    const oldCount = ingredients[type];
    if (oldCount === 0) {
      return;
    }
    const updateCount = oldCount - 1;
    const updateIngredients = {
      ...ingredients,
    };
    updateIngredients[type] = updateCount;
    const priceDeduction = INGREDIENT_PRICES[type];
    const oldPrice = totalPrice;
    const newPrice = oldPrice - priceDeduction;
    setIngredients(updateIngredients);
    setTotalPrice(newPrice);
    updatePurchase(updateIngredients);
  };

  const purchaseHandler = () => {
    setPurchasing(!purchasing);
  };

  const modalHandler = () => {
    setPurchasing(!purchasing);
  };

  const purchaseContinued = () => {
    alert("Order");
  };

  //! render()----------------------------------------------------------

  // todo: disabled={disabledInfo}
  const disabledInfo = {
    ...ingredients,
  };
  for (let key in disabledInfo) {
    disabledInfo[key] = disabledInfo[key] <= 0;
  }

  return (
    <Fragment>
      <Modal show={purchasing} modalClosed={modalHandler}>
        <OrderSummary
          ingredients={ingredients}
          purchaseContinued={purchaseContinued}
          purchaseCancelled={purchaseHandler}
          price={totalPrice}
        />
      </Modal>
      <Burger ingredients={ingredients} />
      <BuildControllers
        ingredientAdded={addIngredientHandler}
        ingredientRemove={removingIngredientHandler}
        disabled={disabledInfo}
        price={totalPrice}
        purchasable={purchasable}
        ordered={purchaseHandler}
      />
    </Fragment>
  );
};

export default BurgerBuilder;
