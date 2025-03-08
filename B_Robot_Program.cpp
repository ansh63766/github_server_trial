#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void process() {
    int length;
    ll start_position, max_steps;
    string directions;
    cin >> length >> start_position >> max_steps >> directions;

    ll initial_hit = 0;
    ll initial_steps = 0;
    bool is_hit = false;
    ll current_position = start_position;
    int current_index = 0;

    for (int index = 0; index < length; ++index) {
        if (initial_steps >= max_steps) break;
        char move = directions[index];
        current_position += (move == 'R' ? 1 : -1);
        initial_steps++;
        if (current_position == 0) {
            initial_hit = 1;
            is_hit = true;
            break;
        }
    }

    if (!is_hit) {
        initial_steps = min(initial_steps, max_steps);
        cout << 0 << '\n';
        return;
    } else {
        if (initial_steps > max_steps) {
            cout << 0 << '\n';
            return;
        }
        ll remaining_steps = max_steps - initial_steps;
        if (remaining_steps == 0) {
            cout << initial_hit << '\n';
            return;
        }

        ll phase2_steps = 0;
        bool phase2_hit = false;
        current_position = 0;
        for (int index = 0; index < length; ++index) {
            char move = directions[index];
            current_position += (move == 'R' ? 1 : -1);
            phase2_steps++;
            if (current_position == 0) {
                phase2_hit = true;
                break;
            }
        }

        ll phase2_hits = 0;
        if (phase2_hit) {
            phase2_hits = remaining_steps / phase2_steps;
            ll remaining_moves = remaining_steps % phase2_steps;
            if (remaining_moves > 0) {
                current_position = 0;
                for (int index = 0; index < remaining_moves; ++index) {
                    char move = directions[index];
                    current_position += (move == 'R' ? 1 : -1);
                    if (current_position == 0) {
                        phase2_hits++;
                        break;
                    }
                }
            }
        } else {
            ll full_cycles = remaining_steps / length;
            ll leftover_moves = remaining_steps % length;
            current_position = 0;
            for (int index = 0; index < leftover_moves; ++index) {
                char move = directions[index];
                current_position += (move == 'R' ? 1 : -1);
                if (current_position == 0) {
                    phase2_hits++;
                    break;
                }
            }
        }

        cout << initial_hit + phase2_hits << '\n';
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        process();
    }

    return 0;
}
