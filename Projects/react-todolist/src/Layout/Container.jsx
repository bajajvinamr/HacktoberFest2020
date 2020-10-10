import React from "react";
import { css } from "@emotion/core";
import PropTypes from "prop-types";

const Container = ({
  children,
  flexDirection,
  flexWrap,
  justifyContent,
  alignItems,
  alignContent,
  height,
}) => {
  const containerStyles = css`
    display: flex;
    flex-direction: ${flexDirection};
    flex-wrap: ${flexWrap};
    justify-content: ${justifyContent};
    align-items: ${alignItems};
    align-content: ${alignContent};
    height: ${height};
  `;

  return (
    <div className="flex-container" css={containerStyles}>
      {children}
    </div>
  );
};

Container.defaultProps = {
  flexDirection: "row",
  flexWrap: "nowrap",
  justifyContent: "flex-start",
  alignItems: "stretch",
  alignContent: "stretch",
};

Container.propTypes = {
  children: PropTypes.oneOfType([
    PropTypes.arrayOf(PropTypes.node),
    PropTypes.node,
  ]),
  flexDirection: PropTypes.oneOf([
    "row",
    "row-reverse",
    "column",
    "column-reverse",
  ]),
  flexWrap: PropTypes.oneOf(["nowrap", "wrap-reverse", "wrap"]),
  justifyContent: PropTypes.oneOf([
    "flex-start",
    "flex-end",
    "center",
    "space-between",
    "start",
    "end",
    "left",
    "right",
    "space-around",
    "space-evenly",
  ]),
  alignItems: PropTypes.oneOf([
    "stretch",
    "flex-start",
    "flex-end",
    "center",
    "start",
    "self-start",
    "end",
    "self-end",
    "baseline",
    "first baseline",
    "last baseline",
    "left",
  ]),
  alignContent: PropTypes.oneOf([
    "stretch",
    "flex-start",
    "flex-end",
    "center",
    "start",
    "end",
    "space-between",
    "space-around",
    "space-evenly",
    "baseline",
    "first baseline",
    "last baseline",
  ]),
  height: PropTypes.oneOfType([PropTypes.number, PropTypes.string]),
};

export default Container;
