import React from "react"
import "../Search.scss"
import { BsArrowRightCircleFill } from "react-icons/bs"
import { useNavigate } from "react-router-dom"
import { useState } from "react"

export default function Search() {
    const [userName, setUserName] = useState('')
    const handleChange = (e) => {
        setUserName(e.target.value);
    }
    const navigate = useNavigate()
    const handleClick = (e) => {
        e.preventDefault()
        navigate(`userInfo/${userName}`)
    }
    return (
        <>
            <div className="container">

                <div className="demo-flex-spacer"></div>

                    <div className="search_header"><h1>Search GitHub Profile</h1></div>
                <div className="webflow-style-input">
                    <input className="" type="text" name="input" placeholder="Enter your username" onChange={handleChange} />
                    <button typename="submit"onClick = {handleClick}><BsArrowRightCircleFill /></button>
                </div>

                <div className="demo-flex-spacer"></div>

            </div>
        </>
    )
}