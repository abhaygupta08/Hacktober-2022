import React, { useEffect, useState } from "react"
import Info from "../Components/info"
import About from "../Components/about"
import Interests from "../Components/interests"
import Footer from "../Components/footer"
import NotFound from "../Components/NotFound"
import Preloader from "../Components/Preloader"
import axios from "axios"
import { UserProfile } from "../config/api"
import { useParams } from "react-router-dom"



export default function InfoPage() {
    const [loading, setLoading] = useState(false)
    useEffect(() => {
        setLoading(true)
        setTimeout(() => {
            setLoading(false)
        }, 3000);
    }, [])
    const [info, setInfo] = useState([])
    const { id } = useParams()
    const fetchprofile = async () => {
        const { data } = await axios.get(UserProfile(id))
        setInfo(data)
    }
    console.log(info)
    useEffect(() => {
        fetchprofile()
    }, [id])
    return (
        <>{ loading? <Preloader/>:

                info.id ?
                    <div id="container">
                        <div className="inner-container">
                            <Info logo={info.avatar_url} userName={info.login} name={info.name} email={info?.email} url={info?.html_url} />
                            <About description={info?.bio} />
                            <Interests followers={info?.followers} following={info?.following} repos={info?.public_repos} />
                            <Footer />
                        </div>
                    </div> :
                    <NotFound />
            }
        </>
    )
}