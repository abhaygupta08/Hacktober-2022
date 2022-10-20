import React from "react"
import { MdEmail } from "react-icons/md";
import { HiHome} from "react-icons/hi";
import { useNavigate } from "react-router-dom";

export default function Info(props){
    const navigate = useNavigate()
    const handleClick = (e)=>{
        e.preventDefault()
        navigate("/profile_Finder")
    }
    return(
        <header className="info-section">
            <img src={props.logo} alt=""></img>
            <div className="info">
                <h1>{props.userName}</h1>
                <h2>{props.name}</h2>
                <h3>{props.email}</h3>
            </div>
            <div className="info-buttons">
                <button type="button" className="email-btn">
                <a href={props.url}><MdEmail className="info-icon"/>GitHub</a></button>
                <button type="button" className="linkedin-btn" onClick={handleClick}><HiHome className="info-icon"/>Home</button>
            </div>
        </header>
    )
}