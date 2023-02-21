import React from 'react';
import { Card, Image, Row, Col } from "react-bootstrap";

  
  const cardOne = ({ user }) => {
    return (
      <Card style={{ width: "100%", margin: "10px 0px 10px 0px" }}>
        
            <Image style={{padding: "20px"}} src={user.image} roundedCircle fluid />
      
            <Card.Body>
              <Card.Title>{user.username}</Card.Title>
              <Card.Text>
                Lorem ipsum dolor sit amet, consectetur adipiscing elit.
              </Card.Text>
            </Card.Body>
          
      </Card>
    );
  };

export default cardOne;