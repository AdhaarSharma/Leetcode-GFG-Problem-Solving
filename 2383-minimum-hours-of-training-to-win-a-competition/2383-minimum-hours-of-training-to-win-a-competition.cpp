class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        int energy_required = 0, exp_required = 0;
        
        int total_energy_expended = 0;
        for(int i=0; i<energy.size(); i++)
            total_energy_expended += energy[i];
        if(total_energy_expended >= initialEnergy)
            energy_required = total_energy_expended-initialEnergy+1;
        
        int curr_experience = initialExperience;
        for(int i=0; i<experience.size(); i++){
            if(curr_experience<=experience[i]){
                int temp = experience[i]-curr_experience+1;
                exp_required += temp;
                curr_experience += temp;
            }
            curr_experience += experience[i];
        }
        
        return (energy_required + exp_required);
    }
};