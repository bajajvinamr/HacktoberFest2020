import React from 'react'
import "./sidebar.css"
import { MdRssFeed } from "react-icons/md";
import { BsChatSquareDotsFill } from "react-icons/bs";
import { BsFillCameraVideoFill } from "react-icons/bs";
import { GrGroup } from "react-icons/gr";
import { BsFillBookmarkCheckFill } from "react-icons/bs";
import { BsFillQuestionCircleFill } from "react-icons/bs";
import { BsFillBagFill } from "react-icons/bs";
import { MdOutlineEmojiEvents } from "react-icons/md";
import { FaGraduationCap } from "react-icons/fa";

export default function Sidebar() {
  return (
    <div className='sidebar'>
        <div className="slidebarwapper">
            <ul className='sidebarList'>
                <li className='sidebarListItems'>
                    <MdRssFeed className='sidebarIcon'/>
                    <span className='feeditem'>Feed</span>
                </li>
                <li className='sidebarListItems'>
                    <BsChatSquareDotsFill className='sidebarIcon'/>
                    <span className='feeditem'>Chats</span>
                </li>
                <li className='sidebarListItems'>
                    <BsFillCameraVideoFill className='sidebarIcon'/>
                    <span className='feeditem'>Video</span>
                </li>
                <li className='sidebarListItems'>
                    <GrGroup className='sidebarIcon'/>
                    <span className='feeditem'>Group</span>
                </li>
                <li className='sidebarListItems'>
                    <BsFillBookmarkCheckFill className='sidebarIcon'/>
                    <span className='feeditem'>Bookmark</span>
                </li>
                <li className='sidebarListItems'>
                    <BsFillQuestionCircleFill className='sidebarIcon'/>
                    <span className='feeditem'>Questions</span>
                </li>
                <li className='sidebarListItems'>
                    <BsFillBagFill className='sidebarIcon'/>
                    <span className='feeditem'>Bags</span>
                </li>
                <li className='sidebarListItems'>
                    <MdOutlineEmojiEvents className='sidebarIcon'/>
                    <span className='feeditem'>Events</span>
                </li>
                <li className='sidebarListItems'>
                    <FaGraduationCap className='sidebarIcon'/>
                    <span className='feeditem'>Courses</span>
                </li>
            </ul>
            <button className='slidebarbtn'>Show More</button>
            <hr className='sidebarhr'/>
{/* -------------------------------------------------------------------------------------------------------             */}
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/2.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/3.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/4.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/5.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/6.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/7.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/8.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/9.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/10.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/4.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
            <ul className='sidebarfriendlist'>
                <li className='sidebarfriend'>
                    <img className='sidebarFriendImg logosize' src='/assets/person/7.jpeg'/>
                    <span className='sidebarfriendname'>Jane Doe</span>
                </li>
            </ul>
{/* -------------------------------------------------------------------------------------------------------             */}

        </div>
    </div>
  )
}
