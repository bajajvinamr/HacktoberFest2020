import React from 'react'
import './post.css'
import { MdOutlineMoreVert } from "react-icons/md";
import {Users} from '../../DummyData'
import { useState } from 'react';



export default function Post({post}) {
  // console.log(post)

  // const user = Users.filter(u=>u.id===1)
    const [like,setLike] = useState(post.like)
    const [islike,setIslike] = useState(false)

    const likehandler = () => {
      setLike(islike ? like-1 : like+1)
      setIslike(!islike)

    } 

  return (
    <div className='post'>
        <div className="postwrapper"></div>
        <div className="posttop">
            <img className='postprofileimg' src={Users.filter((u) => u.id == post.userId)[0].profilePicture} alt="" srcset="" />
            <span className='profilename'>
              {Users.filter((u) => u.id == post.userId)[0].username}
            </span>
            <span className='posttime'>{post.date}</span>
            <MdOutlineMoreVert className='threedots'/>
        </div>

        <div className="postcenter">
            <span className='postdescription'>{post?.desc}</span>
            <img className="postimg" src={post.photo} alt="" srcset="" />

        </div>
        <div className="postbottom">
            <img className='likeheartlogo' src="./assets/like.png" onClick={likehandler} alt="" srcset="" />
            <img className='likeheartlogo' src="./assets/heart.png" onClick={likehandler} alt="" srcset="" />
            <span className='likecount'>{ like} people like it</span>
            <span className='commentcount'>{post.comment} comments</span>


        </div>

    </div>
  )


}

