#include "member.h"

#include <queue>

#include "database.h"

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
  std::queue <Member*> q;
  Member *m = this;
  m->color = 1;
  q.push(m);
  
  while (!(q.empty())){
    Member *n = q.front();
    q.pop();
    for (auto it = n->groups.begin(); it != n->groups.end(); it++){
      Group *g = *it;
      for (auto it2 = g->members.begin(); it2 != g->members.end(); it2++){
        Member *m2 = *it2;
        if (m2->member_id == dst_member_id){
          PrintPath(m2);
          return;
        }
        else if (m2->color == 0){
          m2->color = 1;
          m2->parent = n;
          q.push(m2);
        }
      }
    } 
  }
  
}

void Member::DFS(Member *node, int depth, uint64_t dst_member_id){
  if (depth >= 0 && node->member_id == dst_member_id){
    PrintPath(node);
    return;
  }
  
  if (depth > 0){
    for (auto it = node->groups.begin(); it != node->groups.end(); it++){
      Group *g = *it;
      for (auto it2 = g->members.begin(); it2 != g->members.end(); it2++){
        Member *m2 = *it2;
        if (m2->color == 0){
         m2->parent = node;
         m2->color = 1;
         DFS(m2,depth-1,dst_member_id); 
        }
        
      }
    }
  }
  
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  std::queue <Member*> q;
  Member *m = this;
  m->color = 1;
  
  for (int x = 0; x < 100; x++){
    DFS(m,x,dst_member_id);
  }
}


  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
