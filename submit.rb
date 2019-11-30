class String
  def presence
    self unless self.empty? or self.nil?
  end
end
scan = lambda{gets.chomp.presence}
ignore=<<EOF
.DS_Store
.vscode/*
!.vscode/settings.json
!.vscode/tasks.json
!.vscode/launch.json
bin/*
in/*
EOF
File.open ".gitignore","w" do |f|
  f.write ignore
end
config = {
  email: `git config user.email`.presence || "ha819ha.dev@gmail.com",
  name: `git config user.name`.presence || "devnok",
  github: "https://github.com/devnok/BOJ.git",
  commit_msg: Time.now.strftime("%Y년%m월%d일"),
  boj_path: "~/documents/dev/c++"
}
if Dir.exist?('.git')
    `git pull origin master`
else
  `git init`
  print "BOJ repository : "
  url = scan.call || config[:github]
  puts url
  `git remote add origin #{url}`
end
`git config --local user.email #{config[:email]}`
`git config --local user.name #{config[:name]}`
print "source files path : "
boj_path = File.expand_path(scan.call || config[:boj_path]) #absolute path
puts boj_path
Dir.each_child(boj_path) do |f|
  if File.extname(f) == ".cpp"
    problem = File.basename(f, ".rb").to_i
    if problem > 0
      folder = (problem / 100 * 100).to_s
    else
      folder = "others"
    end
    Dir.mkdir(folder) unless Dir.exist?(folder)
    unless File.exist?("#{folder}/#{f}")
      puts "#{f} generated"
      `cp #{boj_path}/#{f} #{folder}/#{f}`
    end
  end
end

print "commit message : "
commit_msg = scan.call || config[:commit_msg]
puts commit_msg
`git add .`
`git commit -m "#{commit_msg}"`
`git push -u origin master`
