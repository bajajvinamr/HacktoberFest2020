import React from "react";
import Fade from "react-reveal/Fade";
import Section from "elements/Section";
import Clients01 from "assets/images/clients-01.svg";
import Clients02 from "assets/images/clients-02.svg";
import Clients03 from "assets/images/clients-03.svg";
import Clients04 from "assets/images/clients-04.svg";
import Clients05 from "assets/images/clients-05.svg";
export default function Clients() {
  return (
    <div>
      <Section className="clients">
        <Fade bottom delay={2000}>
          <div className="container">
            <div className="clients-inner section-inner has-top-divider has-bottom-divider">
              <ul className="list-reset">
                <li>
                  <img src={Clients01} alt="Clients 01" />
                </li>
                <li>
                  <img src={Clients02} alt="Clients 02" />
                </li>
                <li>
                  <img src={Clients03} alt="Clients 03" />
                </li>
                <li>
                  <img src={Clients04} alt="Clients 04" />
                </li>
                <li>
                  <img src={Clients05} alt="Clients 05" />
                </li>
              </ul>
            </div>
          </div>
        </Fade>
      </Section>
    </div>
  );
}
