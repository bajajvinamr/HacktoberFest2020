import React from 'react'
import "./share.css"
import { GoFileMedia } from "react-icons/go";
import { AiFillTag } from "react-icons/ai";
import { ImLocation2 } from "react-icons/im";
import { BsEmojiSmileFill } from "react-icons/bs";

export default function Share() {
  return (
    <div className='share'>
        <div className='sharewrapper'>
            <div className="sharetop">
            <img className='shareProfileImg' src="./assets/person/1.jpeg"/>
            <input placeholder='Whats in your mind ?' className='shareinput'/>
            </div>
            <hr className='sharehr'/>

            <div className="sharebottom">
                <div className='shareoptions'>
                    <div className="shareoption">
                    <GoFileMedia htmlcolor="grey" className='shareIcon'/>
                    <span className='shareoptiontext'>Photo or Video</span>
                    </div>
                    <div className="shareoption">
                    <AiFillTag className='shareIcon'/>
                    <span className='shareoptiontext'>Tag</span>
                    </div>
                    <div className="shareoption">
                    <ImLocation2 className='shareIcon'/>
                    <span className='shareoptiontext'>Location</span>
                    </div>
                    <div className="shareoption">
                    <BsEmojiSmileFill htmlColor="blue" className='shareIcon'/>
                    <span className='shareoptiontext'>Feelings</span>
                    </div>
                    <button className='sharebutton'>Share</button>

                </div>
                
            </div>
        </div>
    </div>
  )
}
