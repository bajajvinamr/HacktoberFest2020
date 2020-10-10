import React from "react";
import { css } from "@emotion/core";
import PropTypes from "prop-types";

const Item = ({ children, flex, align }) => {
  const itemStyle = css`
    flex: ${flex};
    text-align: ${align};
  `;

  return (
    <div className="flex-item" css={itemStyle}>
      {children}
    </div>
  );
};

Item.propTypes = {
  children: PropTypes.oneOfType([
    PropTypes.arrayOf(PropTypes.node),
    PropTypes.node,
  ]),
  flex: PropTypes.oneOfType([PropTypes.number, PropTypes.string]),
  align: PropTypes.oneOfType(["center", "right", "left", "justify"]),
};

export default Item;
