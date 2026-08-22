class Solution {
public:
    bool isValidSerialization(string preorder) {
        // Approach : using slot concept, we will satrt from slot = 1(root node) every valid node consumes 1 slot and creates 2 slots (net 1 slot)
        // every invalid node or '#' in the string consumes 1 slot and creates 0 slots (net -1 slot)
        
        // Initially, we have one slot available for the root
        int slots = 1;

        stringstream ss(preorder);
        string node;

        // Process each value separated by ','
        while(getline(ss, node, ',')) {

            // Every node occupies one available slot
            slots--;

            // More nodes than available slots -> invalid
            if(slots < 0) {
                return false;
            }

            // A non-null node creates two slots for its children
            if(node != "#") {
                slots += 2;
            }
        }

        // All slots must be exactly filled
        return slots == 0;
    }
};
