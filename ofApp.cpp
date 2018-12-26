#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetCircleResolution(36);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->draw_shape(glm::vec2(222.5, 497.5), 222.5);
	this->draw_shape(glm::vec2(582.5, 137.5), 137.5);

	this->draw_shape(glm::vec2(137.5, 137.5), 137.5);
	this->draw_shape(glm::vec2(360, 85), 85);
	this->draw_shape(glm::vec2(392.5, 222.5), 52.5);
	this->draw_shape(glm::vec2(307.5, 242.5), 32.5);

	this->draw_shape(glm::vec2(582.5, 582.5), 137.5);
	this->draw_shape(glm::vec2(635, 360), 85);
	this->draw_shape(glm::vec2(497.5, 392.5), 52.5);
	this->draw_shape(glm::vec2(477.5, 307.5), 32.5);

}

//--------------------------------------------------------------
void ofApp::draw_shape(glm::vec2 location, float radius) {

	ofPushMatrix();
	ofTranslate(location);

	ofNoFill();
	ofDrawCircle(glm::vec2(), radius * 0.25);

	int deg_span = 15;
	ofFill();
	for (int deg = 0; deg < 360; deg += deg_span) {

		glm::vec2 start = glm::vec2(radius * 0.25 * cos(deg * DEG_TO_RAD), radius * 0.25 * sin(deg * DEG_TO_RAD));
		float length = ofMap(ofNoise(location.x + start.x * 0.05, location.x + start.y * 0.05, ofGetFrameNum() * 0.01), 0, 1, radius * 0.25, radius );
		glm::vec2 end = glm::normalize(start) * length;

		ofDrawLine(start, end);
		ofDrawCircle(end, glm::length(glm::vec2(length, 0) - glm::vec2(length * cos(deg_span * DEG_TO_RAD), length * sin(deg_span * DEG_TO_RAD))) * 0.5);
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}