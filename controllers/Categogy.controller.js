/**
 * controller for creating the category
 * 
 * POST localhost:8888/ecomm/api/v1/categories
 * 
 * {
 *   "name" : "Household"
 *  "descrition" : "This will have all the household item"
 *  }
 * 
 */
const usermodel = require("../models/user.model");

exports.CreateCategory = (req,res)=>{
    name : req.body.name,
    description : req.body.description
}