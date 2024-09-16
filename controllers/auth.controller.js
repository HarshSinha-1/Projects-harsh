/**
 * I need to write the controller / logic to register a user
 */
const bcrypt = require("bcryptjs")
const user_model = require("../models/user.model")
const JWT = require("jsonwebtoken")
exports.signup = async (req, res)=>{
    /**
     * Logic to create the user
     */

    //1. Read the request body
    const request_body = req.body

    //2. Insert the data in the Users collection in MongoDB
    const userObj = {
        name : request_body.name,
        userId : request_body.userId,
        email : request_body.email,
        userType : request_body.userType,
        password : bcrypt.hashSync(request_body.password,8)
    }

    try{

        const user_created = await user_model.create(userObj)
        /**
         * Return this user
         */

        const res_obj = {
            name : user_created.name,
            userId : user_created.userId,
            email : user_created.email,
            userType : user_created.userType,
            createdAt : user_created.createdAt,
            updatedAt : user_created.updateAt
        }
        res.status(201).send(res_obj)

    }catch(err){
        console.log("Error while registering the user", err)
        res.status(500).send({
            message : "Some error happened while registering the user"
        })
    }

    //3. Return the response back to the user

}

exports.signIn = async (req, res) => {
    try {
        // Check if the user id is present in the system
        const user = await user_model.findOne({ userId: req.body.userId });

        if (!user) {
            return res.status(400).send({
                message: "Invalid UserId!"
            });
        }

        // Ensure user.password is defined
        if (!user.password) {
            return res.status(400).send({
                message: "User password is not set!"
            });
        }

        // Check if the password is correct
        const isPasswordValid = bcrypt.compareSync(req.body.password, user.password); // returns true/false

        if (!isPasswordValid) {
            return res.status(401).send({
                message: "Wrong Password!"
            });
        }

        // Using JWT to create a token with a given TTL (Time to live) and return
        const token = JWT.sign({ id: user.userId }, "my secret xyz", { expiresIn: 120 });

        res.status(200).send({
            name: user.name,
            userId: user.userId,
            email: user.email,
            userType: user.userType,
            accessToken: token
        });
       } catch (error) {
          console.error(error);
          res.status(500).send({
            message: "Server error"
        });
    }
};
