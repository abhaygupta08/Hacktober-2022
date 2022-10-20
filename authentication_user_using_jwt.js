var passport=require('passport');
var LocalStrategy=require('passport-local').Strategy;
var User=require('./models/user');
var jwtStrategy=require('passport-jwt').Strategy;
var ExtractJwt=require('passport-jwt').ExtractJwt;

var jwt=require('jsonwebtoken');
var config=require('./config.js');

exports.local=passport.use(new LocalStrategy(User.authenticate()));
passport.serializeUser(User.serializeUser());
passport.deserializeUser(User.deserializeUser());
exports.getToken=function(user){
    return jwt.sign(user,config.secretKey,{expiresIn:3600});

};
var opts={};
opts.jwtFromRequest=ExtractJwt.fromAuthHeaderAsBearerToken();
opts.secretOrKey=config.secretKey;
exports.jwtPassport=passport.use(new jwtStrategy(opts,function(jwt_payload,done){
    console.log(jwt_payload);
    User.findOne({_id:jwt_payload._id},(err,user)=>{
        if(err){
            return done(err,false);
        }
        else if(user){
return done(null,user);
        }
        else{
            return done(null,false);
        }

    })
}))
// exports.verifyUser=function(req,res,next){

//     var token=req.body.token||req.query.token||req.headers['x-access-token'];
//     if(token){
//         jwt.verify(token,config.secretKey,function(err,decoded){


//             if(err){
//                 var err=new Error("you are not authenticated");
//                 err.status=401;
//                 return next(err);
//             }
//             else{
//                 req.decoded=decoded;
//                 next();

//             }

//         })
//     }
//     else{
//         var err=new Error("no token provided");
//         err.status=403;
//         return next(err);
//     }
// }

exports.verifyUser = passport.authenticate('jwt', {session: false});


exports.verifyAdmin=function(res,req,next){
    if(req.user.admin){
        next();
    }
    else{
var err=new Error("You are not authenticated to perform this operation ")
err.status=403;

        return next(err);
    }
}


