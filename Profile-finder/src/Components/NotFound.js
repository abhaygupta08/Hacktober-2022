import React from "react"
import { useNavigate } from "react-router-dom"
import "../NotFound.scss"
export default function NotFound() {
    const navigate = useNavigate()
    const handleClick = (e)=>{
        e.preventDefault()
        navigate('/profile_Finder')
    }
    return (
        <div className="notfound_container">
            <aside className="aside"><img src="https://s3-us-west-2.amazonaws.com/s.cdpn.io/4424790/Mirror.png" alt="404 Image" />
            </aside>
            <main className="main">
                <h1>Sorry!</h1>
                <p>
                    Either you aren't cool enough to visit this page or it doesn't exist <em>. . . like your social life.</em>
                </p>
                <button className="button" onClick={handleClick}>You can go now!</button>
            </main>
        </div>
    )
}