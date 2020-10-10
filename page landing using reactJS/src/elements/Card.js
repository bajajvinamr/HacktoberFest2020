import React from "react";
import propTypes from "prop-types";
import Fade from "react-reveal/Fade";

function Card(props) {
  const className = ["tiles-item"];
  className.push(props.className);
  return (
    <Fade bottom delay={props.delayInMs}>
      <div className={className.join(" ")}>
        <div
          className={`tiles-item-inner ${props.hasShadow ? "has-shadow" : ""}`}
        >
          {props.children}
        </div>
      </div>
    </Fade>
  );
}

Card.propTypes = {
  hasShadow: propTypes.bool,
  className: propTypes.string,
  delayInMs: propTypes.number
};

export default Card;
