# Basic Blocking with Redirection
### User story and solution
When trying to break bad habits, it’s often not effective to stop the habit immediately. Instead, creating barriers or friction can help ease users into reducing their undesirable behavior.  
Similarly, when dealing with websites like Facebook, instead of outright blocking access to the site, we can introduce a system that redirects users to other websites before allowing them access to Facebook. This creates a sense of inconvenience, subtly discouraging excessive use. Over time, the user may feel less inclined to visit the site because of the additional effort involved.

### Features
1. A simple form lets users input alternative websites. When they try to access distracting sites like Facebook or Instagram, they are redirected to these alternatives. If no alternatives are chosen, the extension will directly block access to the distracting websites.
2. A timer feature allows users to set dedicated focus periods. During these times, users will either be redirected or blocked from accessing distracting websites. Outside of these focus periods, users can freely visit these sites as usual. The UI will resemble this design:

<p align="center">
  <img width="736" alt="image" src="https://github.com/user-attachments/assets/a5a42502-25ff-47e4-aa10-15fdc0ca8528">
</p>


