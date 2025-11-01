import React from 'react';
import { User, Brain, LogOut, Settings } from 'lucide-react';
import SentimentAnalyzer from './SentimentAnalyzer';

const Home = ({ user, onLogout, showProfile, setShowProfile }) => {
  return (
    <div className="home-container">
      <nav className="navbar">
        <div className="nav-brand">
          <Brain size={24} />
          <span>Mental Health Monitor</span>
        </div>
        <div className="nav-menu">
          <button 
            className="nav-button"
            onClick={() => setShowProfile(!showProfile)}
          >
            <User size={20} />
            Profile
          </button>
          <button className="nav-button" onClick={onLogout}>
            <LogOut size={20} />
            Logout
          </button>
        </div>
      </nav>
      
      {showProfile ? (
        <div className="profile-section">
          <div className="profile-card">
            <div className="profile-header">
              <User size={60} className="profile-avatar" />
              <h2>{user.name}</h2>
              <p>{user.email}</p>
            </div>
            <div className="profile-actions">
              <button className="profile-button">
                <Settings size={20} />
                Edit Profile
              </button>
              <button 
                className="profile-button secondary"
                onClick={() => setShowProfile(false)}
              >
                Back to Home
              </button>
            </div>
          </div>
        </div>
      ) : (
        <SentimentAnalyzer />
      )}
    </div>
  );
};

export default Home;