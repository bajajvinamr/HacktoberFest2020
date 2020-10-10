import React from 'react';
import './switch.css';

const Switch = ({ isOn, handleToggle }) => {
  return (
    <>
      <input
        onclick="this.blur()"
        checked={isOn}
        onChange={handleToggle}
        className="react-switch-checkbox"
        id={`react-switch-new`}
        type="checkbox"
      />
      <label
        style={{ background: isOn && '#00FF00' }}
        className="react-switch-label"
        htmlFor={`react-switch-new`}
      >
        <span className={`react-switch-button`} />
      </label>
    </>
  );
};

export default Switch;